#include <bits/stdc++.h>
using namespace std;

#define faster ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)
#define vi vector<int>
#define ii pair<int, int>
using ll = long long;

const int N = 3e4, inf = 1e9;
int n, nl, a[N], tr[N];
ii b[N]; vi res;

void inp()
{
    cin >> n;
    for (int i = 0; i < n; ++i)
        cin >> a[i];
}

void sol()
{
    nl = 1;
    b[0] = {-1, -1};
    b[nl] = {inf, -1};
    fill(tr, tr + n, -1);
    for (int i = 0; i < n; ++i)
    {
        int t = upper_bound(b + 0, b + nl + 1, ii(a[i], -1)) - b;
        tr[i] = b[t - 1].second;
        if (b[t].first > a[i])
            b[t] = {a[i], i};
        if (t == nl)
            b[++nl] = {inf, -1};
    }
}

void trace(int i)
{
    if (i == -1)
        return;
    trace(tr[i]);
    cout << a[i] << ' ';
}

int main()
{
    inp();
    sol();
    cout << nl - 1 << '\n';
    trace(b[nl - 1].second);
}