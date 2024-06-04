// #pragma GCC optimize("O3")
// #pragma GCC optimize("Ofast")
#include <bits/stdc++.h>

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
template <class T>
using o_set =
    tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
// order_of_key (val): returns the no. of values less than val
// find_by_order (k): returns the kth largest element.(0-based)
#define int long long
typedef pair<int, int> II;
typedef vector<II> VII;
typedef vector<int> VI;
typedef vector<VI> VVI;
typedef long long LL;
#define PB push_back
#define F first
#define S second
#define ALL(a) a.begin(), a.end()
#define SET(a, b) memset(a, b, sizeof(a))
#define SZ(a) (int)(a.size())
#define FOR(i, a, b) for (int i = (a); i < (int)(b); ++i)
#define fast_io                                                                \
    ios_base::sync_with_stdio(false);                                          \
    cin.tie(NULL)
#define deb(a) cerr << #a << " = " << (a) << endl;
#define deb1(a)                                                                \
    cerr << #a << " = [ ";                                                     \
    for (auto it = a.begin(); it != a.end(); it++)                             \
        cerr << *it << " ";                                                    \
    cerr << "]\n";
#define endl "\n"
const long long mod = 1e9 + 7;

void solve() {
    int n, m, k;
    cin >> n >> m >> k;
    VI cols;
    cols.push_back(m + 1);
    VII pts(k);
    map<int, VII> fts;
    FOR(i, 0, k) {
        cin >> pts[i].first >> pts[i].second;
        cols.push_back(pts[i].second);
        fts[pts[i].second].push_back({pts[i].first, i});
    }
    fts[m + 1].push_back({n, -1});
    VI isImp(k, 0);
    int currCol = 1;
    int currRow = 1;
    sort(ALL(cols));
    cols.erase(unique(ALL(cols)), cols.end());
    int ans = 0;
    for (auto c : cols) {
        sort(ALL(fts[c]), greater<II>());

        for (auto [r, ind] : fts[c]) {
            if (r < currRow)
                continue;
            else {
                ans += (c - currCol) * (n - currRow + 1);
                currRow = r + 1;
                currCol = c;
                if (ind != -1)
                    isImp[ind] = 1;
            }
        }
    }

    cout << ans << endl;
    FOR(i, 0, k)
    cout << isImp[i] << " ";
    cout << endl;
}

signed main() {
    fast_io;
    //  freopen("input.txt", "r", stdin);
    //  freopen("output.txt", "w", stdout);
    int totalTests = 1;
    cin >> totalTests;
    for (int testNo = 1; testNo <= totalTests; testNo++) {
        // cout << "Case #" << testNo << ": ";
        solve();
    }
    return 0;
}
