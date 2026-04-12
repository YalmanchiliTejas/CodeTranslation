N = int(input())
H = str(input())
ls_H = H.split(' ')
ls_H_i = [int(s) for s in ls_H]
MAX_H = ls_H_i[0]
count = 1
i = 2
while i <= N:
    if MAX_H <= ls_H_i[i-1]:
#        print (i, ls_H_i[i-1])
        count += 1
        MAX_H = ls_H_i[i-1]
    i += 1
print (count)