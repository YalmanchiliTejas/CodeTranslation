n = int(input())
h = list(map(int, input().split()))

t = 0
ref = []

for i in range(n):
  ref.append(h[i])
  if h[i] == max(ref):
    t += 1
    
print(t)