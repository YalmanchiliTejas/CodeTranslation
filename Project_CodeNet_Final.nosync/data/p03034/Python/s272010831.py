N = int(input())
s = [int(i) for i in input().split()]
ans = 0
for i in range(1, N-2):
    p = 0
    a = N-1
    k = 0
    while True:
        k += 1
        a -= i
        b = a-i
        if b>0 and a!= N-1-a and a!=N-1-a-i:
            p += (s[a] + s[N-1-a])
            ans = max(ans, p)
        else:
            break
print(ans)