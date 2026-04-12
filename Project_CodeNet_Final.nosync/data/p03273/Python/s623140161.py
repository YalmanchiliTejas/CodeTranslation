h,w = map(int,input().split())
m = []

for i in range(h):
    m.append(list(input()))


#行に着目
dl = []

for i in range(h):
    if all(j =='.' for j in m[i]):
        dl.append(int(i))
# print(dl)
if dl:
    for i in dl:
        del m[i-dl.index(i)]
h = len(m)
# print(m)

dl = []
for i in range(w):
    s = ''
    for j in range(h):
        s = s + m[j][i]
    if all(j == '.' for j in list(s)):
        dl.append(int(i))
# print(dl)
if dl:
    for i in range(h):
        for j in dl:
            del m[i][j-dl.index(j)]

# print(m)
for i in range(h):
    print(''.join(m[i]))

#転置して同様
# m = list(zip(*m)) 
# if m:
#     dl = []
#     for i in range(w):
#         if all(j =='.' for j in m[i]):
#             dl.append(int(i))

#     if dl:
#         for i in range(len(dl)):
#             del m[dl[len(dl)-i-1]]
            


# #転置して元に戻す
# m = list(zip(*m))


# #出力
# for i in range(len(m)):
#     m[i] = ''.join(m[i])
#     print(m[i])