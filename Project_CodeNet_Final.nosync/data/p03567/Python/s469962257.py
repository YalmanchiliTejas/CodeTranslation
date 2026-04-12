s = input()
length = len(s)

flag = False
for i in range(length-1):
    if s[i] == 'A' and s[i+1] =='C':
        flag = True
        break
        
if flag:
    print("Yes")
else:
    print("No")