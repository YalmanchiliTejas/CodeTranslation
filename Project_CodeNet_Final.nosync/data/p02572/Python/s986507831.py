n = int(input())
an = list(map(int,input().split()))

mod = 10**9 + 7
total =sum(an)
ans = 0
z = an[0]

for x in range(n-1):
  nokori = total-z
  ans += an[x] * nokori % mod
  z += an[x+1]

    
ans = ans % mod    
print(ans)
    