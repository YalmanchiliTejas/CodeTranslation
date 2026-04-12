# def calc(n):
#     return "plus" if n > 0 else "minus"
# 
# n =int(input())
# 
# array = [int(x) for x in input().split()]
# tmp = calc(array[0])
# tmp2 = 0
# res = 0
# 
# for x in range(len(array)-1):
#     tmp2 = (array[x] - array[x+1])
#     if tmp == calc(tmp2):
#         if tmp2 == "minus":
#             tmp2 = 1
#             res += (1 - tmp2)
#         else:
#             tmp2 = -1
#             res += (1 - tmp2)
# print(res)


n = int(input())
s = list()
for i in range(n):
    s.append(input())

res = ""
for c in "abcdefghijklmnopqrstuvwxyz":
    c_min = list()
    for j in s:
        cnt = 0
        for k in j:
            if k == c:
                cnt += 1
        c_min.append(cnt)
    res += c * min(c_min)

print(res)
