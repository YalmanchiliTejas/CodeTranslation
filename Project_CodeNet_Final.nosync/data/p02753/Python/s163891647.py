#A
#入力

S=input()

#処理

if S[0]!=S[1]:
    print("Yes")
elif S[1]!=S[2]:
    print("Yes")
elif S[0]!=S[2]:
    print("Yes")
else:
    print("No")