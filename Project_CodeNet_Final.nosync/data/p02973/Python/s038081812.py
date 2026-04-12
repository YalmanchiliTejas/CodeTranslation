N = int(input())
a = int(input())
l = [a]
d = {a: 1}
ans = 1
for _ in range(1, N):
    a = int(input())
    if a in d:
        d[a] += 1
        if l[-1] == a:
            ans += 1
        else:
            i = l.index(a) + 1
            v = l[i]
            if d[v] == 1:
                del d[v]
                l.remove(v)
            else:
                d[v] -= 1
    else:
        v = l[0]
        if v < a:
            if d[v] == 1:
                del d[v]
                l[0] = a
            else:
                d[v] -= 1
                l.insert(0, a)
        elif l[-1] > a:
            l.append(a)
            ans += 1
        else:
            left, right = 0, len(l) - 1
            while left + 1 != right:
                i = (left + right) // 2
                x = l[i]
                if x > a:
                    left = i
                else:
                    right = i
            v = l[right]
            if d[v] == 1:
                del d[v]
                l[right] = a
            else:
                d[v] -= 1
                l.insert(right, a)
        d[a] = 1
print(ans)
