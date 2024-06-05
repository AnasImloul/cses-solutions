#include <iostream>
#include <vector>
#include <climits>

using namespace std;

using ll = long long;

int n, k;

vector<ll> nums, prefix;
vector<vector<ll>> dp;

ll solve(int i, int j) {
    if (j == 1) return (prefix[n] - prefix[i]) * (prefix[n] - prefix[i]);
    if (i == n) return 0;
    if (dp[i][j] != -1) return dp[i][j];

    ll res = LLONG_MAX;
    for (int _i = i; _i < n; _i++) {
        if ((_i - i) > 2 * (n / j + 3)) break;
        ll sum = prefix[_i + 1] - prefix[i];
        res = min(res, sum * sum + solve(_i + 1, j - 1));
    }

    return dp[i][j] = res;
}

int main() {
    cin >> n >> k;

    nums.resize(n), prefix.resize(n + 1, 0);
    for (int i = 0; i < n; i++) {
        cin >> nums[i];
        prefix[i + 1] = prefix[i] + nums[i];
    }

    dp.resize(n + 1, vector<ll>(k + 1, -1));

    cout << solve(0, k) << endl;
}