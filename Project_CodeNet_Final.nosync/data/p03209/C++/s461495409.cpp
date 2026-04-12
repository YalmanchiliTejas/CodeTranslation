#include <bits/stdc++.h>

uint64_t remain = 0;
std::unordered_map<uint64_t, uint64_t> layerCache;
std::unordered_map<uint64_t, uint64_t> cache;

uint64_t levelNLayer(uint64_t n)
{
    if (1 == layerCache.count(n)) {
        return layerCache[n];
    }

    uint64_t cnt = 0;
    if (n == 0) {
        return 1;
    } else {
        cnt += 3;
        if (1 == layerCache.count(n-1)) {
            cnt += (2 * layerCache[n-1]);
        } else {
            uint64_t cnt1 = levelNLayer(n-1);
            cnt += (2 * cnt1);
            layerCache[n-1] = cnt1;
        }

        return cnt;
    }
}

uint64_t levelN(uint64_t n)
{
    uint64_t cnt = 0;

    if (remain == 0) {
        return 0;
    }

    if (n == 0) {
        remain--;
        return 1;
    } else {
        remain--;
        if (1 == cache.count(n-1)) {
            uint64_t layerCnt = levelNLayer(n-1);
            if (layerCnt <= remain) {
                cnt+= cache[n-1];
                remain -= layerCnt;
            } else {
                cnt += levelN(n-1);
            }
        } else {
            uint64_t cnt1 = levelN(n-1);
            if (remain != 0) {
                cache[n-1] = cnt1;
            }
            cnt += cnt1;
        }

        if (remain == 0) {
            return cnt;
        }

        remain--;
        cnt++;

        if (levelNLayer(n-1) <= remain) {
            cnt += cache[n-1];
            remain -= levelNLayer(n-1);
        } else {
            cnt += levelN(n-1);
        }
        if (remain == 0) {
            return cnt;
        }

        remain--;
        return cnt;
    }
}

int main()
{
    uint64_t n;
    std::cin >> n >> remain;

    uint64_t cnt = levelN(n);
    std::cout << cnt << std::endl;

    return 0;
}