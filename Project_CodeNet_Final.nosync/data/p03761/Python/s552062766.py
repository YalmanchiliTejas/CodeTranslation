n = int(input())
dict_list = [{'a':0, 'b':0, 'c':0, 'd':0, 'e':0, 'f':0, 'g':0, 'h':0, 'i':0, 'j':0, 'k':0, 'l':0, 'm':0, 'n':0, 'o':0, 'p':0, 'q':0, 'r':0, 's':0, 't':0, 'u':0, 'v':0, 'w':0, 'x':0, 'y':0, 'z':0} for i in range(n)]

for i in range(n):
    S = input()
    for s in S:
        dict_list[i][s] += 1

dic = {'a':0, 'b':0, 'c':0, 'd':0, 'e':0, 'f':0, 'g':0, 'h':0, 'i':0, 'j':0, 'k':0, 'l':0, 'm':0, 'n':0, 'o':0, 'p':0, 'q':0, 'r':0, 's':0, 't':0, 'u':0, 'v':0, 'w':0, 'x':0, 'y':0, 'z':0}
for k, v in dic.items():
    dic[k] = 100
    for j in range(n):
        dic[k] = min(dict_list[j][k], dic[k])

W = []
for k, v in dic.items():
    for i in range(v):
        W.append(k)

W.sort()
W = ''.join(W)

print(W)
