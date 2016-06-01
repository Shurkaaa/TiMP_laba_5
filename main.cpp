#include <iostream>
#include <string>
#include <vector>


using namespace std;


void add(int k, vector<int>& q);
int left(int i) { return 2*i + 1; }
int right(int i) { return 2*i + 2; }
int parent(int i) { return i/2 - (1 - i%2); }


int main(void) {
    vector<int> q;
    int N;
    cin >> N;
    
    while (N-- >= 0) {
        string cmd;
        cin >> cmd;
        
        if (cmd == "add") {
            int k;
            cin >> k;
            add(k, q);
        } else if (cmd == "get")
            cout << q[0] << endl;
        else if (cmd == "del")
            q.erase(q.cbegin());
    }
    
    return 0;
}


void add(int k, vector<int>& q) {
    q.push_back(k);
    
    int p, i = q.size()-1;
    while ((q[p = parent(i)] > q[i]) && (i != 0)) {
        swap(q[i], q[p]);
        i = p;
    }
    
    return;
}