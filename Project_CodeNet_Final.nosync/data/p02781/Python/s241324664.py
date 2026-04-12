import sys

def comb(n, k):
    if k == 0:
        return 0
    if n < k:
        return 0
    res=1
    for i in range(n - k + 1, n + 1):
        res *= i
    for i in range(1,k + 1):
        res //= i
    return res

n=input()
k = int(input())
l = len(n)

top = int(n[0])

if l == 1:
    if k >= 2:
        print(0)
        sys.exit()
    print(top)
    sys.exit()

if k == 1:
    z = 9
elif k == 2:
    z = 81
else:
    z = 729

ans = comb(l - 1, k) * z
ans += comb(l - 1, k - 1) * (top - 1) * (z // 9)

if k == 1:
    ans+=top
elif k == 2:
    for i in range(1, l):
        if i==1 or int(n[1:i]) == 0:
            ans += int(n[i])
        else:
            ans += 9
elif k == 3:
    for i in range(1, l):
        for j in range(i + 1, l):
            flag1 = i == 1 or int(n[1:i]) == 0
            flag2 = j == i + 1 or int(n[i + 1 :j]) == 0
            if not(flag1) and not(flag2):
                ans += 81
            elif flag1 and not (flag2):
                ans += 9 * int(n[i])
            elif not (flag1) and flag2:
                ans += 81
            else:
                if int(n[i]) == 0:
                    continue
                ans += 9 * (int(n[i]) - 1) + int(n[j])

print(ans)
