A,B,C = list(map(int,input().split()))
ans = 0
if B + C * 2 > A:
    print(ans)
    exit()
A -= B + C * 2
ans += 1
while A // (B+C) >= 1:
    A -= B + C 
    ans += 1
print(ans)