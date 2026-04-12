n = int(input())
li = list(map(int, input().split()))
max_ = 0
s = 0
for i in li:
  if max_ <= i:
    max_ = i
    s += 1
print(s)