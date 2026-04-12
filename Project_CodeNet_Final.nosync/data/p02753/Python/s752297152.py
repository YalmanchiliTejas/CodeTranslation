s = input()
flag = 0

for i in range(3):
    for j in range(3):
        if s[i] != s[j]:
            flag =1

if flag ==1 :
    print("Yes")
else:
    print("No")