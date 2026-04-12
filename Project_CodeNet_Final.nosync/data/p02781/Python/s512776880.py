n = list(map(int, list(input())))
k = int(input())
l = len(n)

ans = 0
if k == 1:
    ans = n[0] + (l - 1) * 9
elif k == 2:
    if l == 1:
        ans = 0
    else:
        for i in range(l - 1):
            p = True
            for j in range(i + 1, l):
                if i == 0 and p:
                    ans += (n[i] - 1) * 9 + n[j]
                elif i == 0:
                    ans += n[i] * 9
                else:
                    ans += 9 * 9
                if n[j] != 0:
                    p = False
else:
    if l <= 2:
        ans = 0
    else:
        for i in range(l - 2):
            p1 = True
            for j in range(i + 1, l - 1):
                p2 = True
                for k in range(j + 1, l):
                    if i == 0 and p1 and p2:
                        ans += (n[i] - 1) * 9 * 9
                        ans += (n[j] - 1) * 9 + n[k] if n[j] != 0 else 0
                    elif i == 0 and p1 and not p2:
                        ans += (n[i] - 1) * 9 * 9 + n[j] * 9
                    elif i == 0 and not p1:
                        ans += n[i] * 9 * 9
                    else:
                        ans += 9 * 9 * 9
                    if n[k] != 0:
                        p2 = False
                if n[j] != 0:
                    p1 = False
print(ans)
