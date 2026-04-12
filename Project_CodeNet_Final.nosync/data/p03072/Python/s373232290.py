n = input()
arr = list(map(int,input().split(" ")))

m = arr[0]
ans = 0
for a in arr:
  if a>=m: 
    ans += 1
    m = a
print(ans)