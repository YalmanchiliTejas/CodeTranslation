n = int(input())
s = input().split()  # n個横並びに入力されるとき

for i in range(n):
    s[i] = int(s[i])

count = 1
biggest = s[0]

for i in range(n-1):
    if(biggest <= s[i+1]):
        count += 1
        biggest = s[i+1]

print(count)
