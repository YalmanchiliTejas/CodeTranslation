s = input().split()
x = int(s[0])
y = int(s[1])
z = int(s[2])

p = x - z

answer = int(p / (y + z))

print(answer)