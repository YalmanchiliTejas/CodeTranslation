import collections

N = int(input())
l = [input() for _ in range(N)]


alp_list = list("abcdefghijklmnopqrstuvwxyz")

alp_count = {}

res = ""

for i in l:
    c = collections.Counter(i)
    #print(c)
    for j in alp_list:
        if j in c.keys():
            if j not in alp_count:
                alp_count[j] = c[j]
            else:
                alp_count[j] = min(alp_count[j],c[j])
        else:
            alp_count[j] = 0

#print(alp_count)

for i in alp_list:
    if i in alp_count:
        res += i * alp_count[i]

print(res)