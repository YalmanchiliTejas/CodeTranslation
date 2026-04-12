n = int(input())

s = input().split(" ")

sumup = 0
for i in s:
  sumup += int(i) 

ans = 0
for i in s:
  r = int(i)
  
  sumup -= r
  
  ans += r*sumup
    
print(ans%(10**9+7))
