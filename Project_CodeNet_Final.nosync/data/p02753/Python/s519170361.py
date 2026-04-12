S = input()

for i in range(2):
    if S[i] != S[i+1]:
        print('Yes')
        exit()
print('No')