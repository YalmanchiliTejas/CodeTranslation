n = int(input()) 
t = list(map(int, input().split()))
counter = 1
for i in range(n-1):
  if max(t[:i+1]) <= t[i+1]:
    counter += 1

print(counter)
