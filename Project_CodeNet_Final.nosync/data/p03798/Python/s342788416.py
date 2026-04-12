n = int(input())
s = input()

# S:1 W:-1
T = [[1, 1], [1, -1], [-1, 1], [-1, -1]]
for t in T:
    for i in range(n-1):
        if t[i+1] == 1:
            if s[i+1] == "o":
                t.append(t[i])
            else:
                t.append(-1*t[i])
        else:
            if s[i+1] == "o":
                t.append(-1*t[i])
            else:
                t.append(t[i])
#print(T)
for t in T:
    if t[0] == t[-1]:
        if t[0] == 1:
            if s[0] == "o" and t[-2] == t[1]:
                ans = t
                break
            elif s[0] == "x" and t[-2] != t[1]:
                ans = t
                break
        elif t[0] == -1:
            if s[0] == "o" and t[-2] != t[1]:
                ans = t
                break
            elif s[0] == "x" and t[-2] == t[1]:
                ans = t
                break
else:
    print(-1)
    exit()


str_ans = ""
for i in range(n):
    if ans[i] == 1:
        str_ans += "S"
    elif ans[i] == -1:
        str_ans += "W"
print(str_ans)


