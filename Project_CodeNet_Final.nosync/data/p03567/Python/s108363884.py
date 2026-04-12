S = input()
for i in range(len(S) - 1):
    if S[i:i + 2] == "AC":
        print('Yes')
        break
else:
    print('No')
