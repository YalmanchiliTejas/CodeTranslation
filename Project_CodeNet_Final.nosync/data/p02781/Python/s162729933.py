from functools import lru_cache
n = list(map(int, list(input())))
k = int(input())

@lru_cache(10**9)
def rec(keta, cnt, tight):
    if cnt > k:
        return 0
    if keta==len(n):
        if cnt==k:
            return 1
        else:
            return 0
    ret = 0
    for i in range(10):
        if tight and i > n[keta]:
            break
        ret += rec(keta+1, cnt+int(i!=0), tight and i==n[keta])
    return ret

ans = rec(0,0, True)
print(ans)