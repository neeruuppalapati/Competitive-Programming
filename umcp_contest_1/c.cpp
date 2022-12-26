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

int check(string& a, string& b, string& c, bool add) {
	if (add) return stoll(a) + stoll(b) == stoll(c);
	return stoll(a) * stoll(b) == stoll(c);
}

void solve() {
	string a, b, c;
	string g, op;
	bool add = false;
	cin >> a >> op >> b >> g >> c;
	if (op == "+") add = true;
	for (int i = 1; i < a.size(); i++) {
		for (int j = 1; j < b.size(); j++) {
			string aa = a.substr(0, i) + b.substr(j);
			string bb = b.substr(0, j) + a.substr(i);
			if (check(bb, aa, c, add)) {
				cout << aa << " " << op << " " << bb << " = " << c << endl;
				return;
			}
		}
		for (int j = 1; j < c.size(); j++) {
			string aa = c.substr(0, j) + a.substr(i);
			string cc = a.substr(0, i) + c.substr(j);
			if (check(aa, b, cc, add)) {
				cout << aa << " " << op << " " << b << " = " << cc << endl;
				return;
			}
		}
	}
	for (int i = 1; i < b.size(); i++) {
		for (int j = 1; j < c.size(); j++) {
			string bb = c.substr(0, j) + b.substr(i);
			string cc = b.substr(0, i) + c.substr(j);
			if (check(a, bb, cc, add)) {
				cout << a << " " << op << " " << bb << " = " << cc << endl;
				return;
			}
		}
	}


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

