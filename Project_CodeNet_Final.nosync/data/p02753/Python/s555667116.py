S = input()

flag = True
X = S[0]

for i in range(1, 3):
    if S[i] != X:
        flag = False
        
if flag:
    print("No")
else:
    print("Yes")