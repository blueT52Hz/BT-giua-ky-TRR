#include <iostream>
#include <vector>
#define ll long long
#define pb push_back
using namespace std;

int n, x, lienThong = 0;
vector<vector<int>> res;
vector<vector<int>> e;
vector<int> vs;

void dfs(int u) {
    res[lienThong].push_back(u);
    vs[u] = 1;
    for (int i = 0; i < e[u].size(); ++i) {
        int v = e[u][i];
        if (vs[v] == 0) {
            dfs(v);
        }
    }
}

int main() {
	ios_base :: sync_with_stdio (0); cin.tie(0); cout.tie(0);
    cin >> n;
    e.resize(n + 1);
    vs.resize(n + 1, 0);
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= n; ++j) {
            int x; cin >> x;
            if (x == 1) e[i].push_back(j);
        }
    }
    for (int i = 1; i <= n; ++i) {
        if (vs[i] == 0) {
            res.resize(lienThong + 1);
            dfs(i);
            lienThong++;
        }
    }
	if (res.size() == 0) cout << "No spanning tree";
    for (int i = 0; i < res.size(); ++i) {
        cout << "Thanh phan lien thong " << i + 1 << "\n";
        for (int j : res[i]) {
            cout << j << " ";
        }
        cout << endl;
    }
    return 0;
}