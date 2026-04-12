S = input()
for i in range(2):
    if  S[i] == S[i+1]:
        pass
    else:
        print("Yes")
        exit()
print("No")