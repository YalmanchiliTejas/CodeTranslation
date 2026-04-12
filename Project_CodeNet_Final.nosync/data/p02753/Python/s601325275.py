s = str(input())
apple = []
for i in s:
    apple.append(i)
print("Yes" if len(set(apple)) == 2 else "No")