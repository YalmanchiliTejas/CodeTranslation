n = int(input())
a = [int(input()) for _ in range(n)]


b = []

for ai in a:
    if len(b) == 0:
        b.append(ai)
    else:
        if ai <= b[-1]:
            b.append(ai)
        else:
            l = -1
            r = len(b)
            mid = (l + r) // 2
            while (r - l > 1):
                mid = (l + r) // 2
                if b[mid] >= ai:
                    l = mid
                else:
                    r = mid
            b[r] = ai

print(len(b))
