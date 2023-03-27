#include <bits/stdc++.h>

using namespace std;

int n;
int seg[4 * 100], v[100];

int build(int p, int l, int r) {
	if(l == r) {
		return seg[p] = v[l];
	}
	int mid = (l + r) / 2;
	return seg[p] = build(2 * p, l, mid) + build(2 * p + 1, mid + 1, r); 
}

int update(int i, int x, int p, int l, int r) {
	if(i < l || i > r) {
		return seg[p];
	}
	if(l == r) {
		return seg[p] = x;
	}
	int mid = (l + r) / 2;
	return seg[p] = update(i, x, 2 * p, l, mid) + update(i, x, 2 * p + 1, mid + 1, r);
}

int query(int a, int b, int p, int l, int r) {
	if(b < l || a > r) {
		return 0;
	}
	if(l >= a && r <= b) {
		return seg[p];
	}
	int mid = (l + r) / 2;
	return query(a, b, 2 * p, l, mid) + query(a, b, 2 * p + 1, mid + 1, r);
}

int main() {
	cin >> n;
	for(int i = 0; i < n; i++) {
		cin >> v[i];
	}
	build(1, 0, n - 1);
	int q;
	cin >> q;
	while(q--) {
		int op;
		cin >> op;
		if(op == 1) {
			int a, b;
			cin >> a >> b;
			a--, b--;
			cout << query(a, b, 1, 0, n - 1) << '\n';
		}
		else {
			int i, x;
			cin >> i >> x;
			--i;
			update(i, x, 1, 0, n - 1);
		}
	}
}
