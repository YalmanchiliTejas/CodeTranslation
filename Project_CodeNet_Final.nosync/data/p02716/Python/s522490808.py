n = int(input())
a = [int(ai) for ai in input().split()]
if n % 2 == 0:
    s = [0,0]
    for i in range(n // 2):
        s = [max(s[q] for q in range(p+1)) + a[i*2+p] for p in range(2)]
    print(max(s))
else:
    s = [0,0,0]
    for i in range(n // 2):
        s = [max(s[q] for q in range(p+1)) + a[i*2+p] for p in range(3)]
    print(max(s))
