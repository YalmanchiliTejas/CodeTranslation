N = int(input())
s_cnt = []
for i in range(N):
    cnt = {}
    s = input()
    for si in s:
        if si in cnt:
            cnt[si] += 1
        else:
            cnt[si] = 1
    s_cnt.append(cnt)
min_ = {}
for i in s_cnt:
    for j in i:
        if any([j not in s_cnt[k] for k in range(N)]):
               continue
        if j not in min_:
            min_[j] = i[j]
        else:
            min_[j] = min(min_[j], i[j])
string = ''
for i in min_:
    #list_.append(i * min_[i])
    string += i * min_[i]
s = sorted(string)
print(''.join(s))