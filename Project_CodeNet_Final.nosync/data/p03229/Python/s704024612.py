n = int(input())
vs = sorted([int(input()) for _ in range(n)])

def do(i):
    if i==0:
        return 0, 1
    else:
        return i+1, i-1
    
score = 0
for i in range(n//2):
    a, b = do(i)
    score += vs[-a-1] + vs[-b-1] - vs[i]*2
if n % 2 == 1:
    v = (vs[(n//2)+1] - vs[n//2]) - (vs[(n//2)] - vs[(n//2)-1])
    if v > 0:
        score += v
print(score)