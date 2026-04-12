# A
S = input()

res = 0
for i in range(len(S) - 1):
    if S[i:(i+2)] == "AC":
        res = 1
        break
        
if res == 0:
    print("No")
else:
    print("Yes")