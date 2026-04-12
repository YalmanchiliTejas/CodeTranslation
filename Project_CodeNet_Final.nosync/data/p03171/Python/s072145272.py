N = int(input())
a = tuple(map(int, input().split()))

def main():
    l = [[0] * N for _ in range(N)]
    for i in range(N):
        for j in range(N):
            if i + j >= N:
                continue
            s = j
            e = j + i
            if len(a) % 2 != i % 2:
                if i == 0:
                    l[s][e] = a[s]
                elif i == 1:
                    l[s][e] = max(a[s:e+1]) - min(a[s:e+1])
                else:
                    l[s][e] = max(a[s] + l[s+1][e], a[e] + l[s][e-1])
            else:
                if i == 0:
                    l[s][e] -= a[s]
                elif i == 1:
                    l[s][e] = min(a[s:e+1]) - max(a[s:e+1])
                else:
                    l[s][e] = min(l[s+1][e] - a[s], l[s][e-1] - a[e])


    return l[0][-1]
print(main())
