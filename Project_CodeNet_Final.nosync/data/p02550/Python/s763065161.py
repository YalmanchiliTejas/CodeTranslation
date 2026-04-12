N, X, M = map(int, input().split())
table = [0]*(M+1)

pre = X
table[pre] = 0
seq = [pre]
cnt = 0
while True:
    cnt += 1
    A = pre**2%M
    if not table[A]:
        seq.append(A)
        table[A] = cnt
        pre = A
    else:
        f = table[A]
        s = cnt
        break
    
ans = 0
for i in range(f + (N-f)%(s-f)):
    ans += seq[i]
m = (N-f)//(s-f)
for i in range(f, s):
    ans += seq[i]*m

print(ans)