#include <bits/stdc++.h>

using namespace std;

template<typename A, typename B> ostream& operator<<(ostream &os, const pair<A, B> &p) { return os << '(' << p.first << ", " << p.second << ')'; }
template<typename T_container, typename T = typename enable_if<!is_same<T_container, string>::value, typename T_container::value_type>::type> ostream& operator<<(ostream &os, const T_container &v) { os << '{'; string sep; for (const T &x : v) os << sep << x, sep = ", "; return os << '}'; }
void dbg_out() { cerr << endl; }
template<typename Head, typename... Tail> void dbg_out(Head H, Tail... T) { cerr << ' ' << H; dbg_out(T...); }
#ifdef LOCAL
#define dbg(...) cerr << "(" << #__VA_ARGS__ << "):", dbg_out(__VA_ARGS__)
#else
#define dbg(...)
#endif

#define ar array
#define ll long long
#define ld long double
#define sza(x) ((int)x.size())
#define all(a) (a).begin(), (a).end()

const int MAX_N = 1e5 + 5;
const ll MOD = 1e9 + 7;
const ll INF = 1e9;
const ld EPS = 1e-9;



void solve() {
	ll n, m; cin >> n >> m;
	ll ans = 1e9;
	// adj list of culminating chapters
	vector<ll> pages(n);
	for (int i = 0; i < n; i++) {
		cin >> pages[i];
	}
	vector<ll> parent(n, -1);
	unordered_set<ll> pre;
	for (int i = 0; i < m; i++) {
		int a, b; cin >> a >> b;
		parent[b-1] = a-1;
		pre.insert(a-1);
	}
	for (int i = 0; i < n; i++) {
		if (!pre.count(i)) {
			unordered_set<ll> vis;
			ll cur = i;
			ll ret = 0;
			while (parent[cur] != -1) {
				ret += pages[cur];
				cur = parent[cur];
				vis.insert(cur);
			}
			ret += pages[cur];
			vis.insert(cur);
			for (int j = 0; j < n; j++) {
				if (!pre.count(j) && i != j) {
					int jc = j;
					int jr = 0;
					while (parent[jc] != -1 && !vis.count(jc)) {
						jr += pages[jc];
						jc = parent[jc];
					}
				
					if (!vis.count(jc)) {
						jr += pages[jc];
					}
					ans = min(ans, ret + jr);
				}

			}
		}
	}
	cout << ans;
}




int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	int tc = 1;
	 //cin >> tc;
	for (int t = 1; t <= tc; t++) {
		 // cout << "Case #" << t << ": ";
		solve();
	}
}

