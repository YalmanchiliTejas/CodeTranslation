n=str(input())
l="753"
flag = 0
for m in l:
    if m in n:
        flag = 1
print("YES" if flag ==1 else "NO")