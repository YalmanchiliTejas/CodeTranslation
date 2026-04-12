S = input()
NS = [0]*len(S)
for i in range(len(S)):
    NS[i] = S[i]

#print(NS)
#print(len(set(NS)))

if len(set(NS)) == 1:
    print('No')
else:
    print('Yes')
