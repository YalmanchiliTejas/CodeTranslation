H, W=list(map(int,input().split()))
a=[list(input()) for _ in range(H)]
b=[]
# print(a)
for i in range(len(a)):
    ct=0
    for j in range(len(a[0])):
        if a[i][j]=='#':
            ct+=1
    if ct!=0:
        b.append(a[i])
# print(b)
c=[[] for _ in range(len(b))]
# print(c)
for i in range(len(b[0])):
    ct=0
    for j in range(len(b)):
        if b[j][i]=='#':
            ct+=1
    if ct!=0:
        for k in range(len(b)):
            c[k].append(b[k][i])
            # print(c, k, i)
# print(c)

for i in range(len(c)):
    print(''.join(c[i]))

# print(a)
# for i in range(len(a[0]))):
#     ct=0
#     for j in range(max(len(a),0)):
#         if a[j][i]=='#':
#             ct+=1
#     if ct==0:
#         for k in range(max(len(a),0)):
#             a[k].pop(i)
#     print(a)
# print(a)
# for i in range(len(a)):
#     print(''.join(a[i]))
