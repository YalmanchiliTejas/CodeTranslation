n = int(input())
s = input()

# 一匹目、二匹目について4通り試す
# 羊:True, 狼:False
from itertools import product
for tf in product([True, False], repeat=2):
    tf = list(tf)
    for i in range(1, n):
        if s[i] == 'o':
            if tf[i]:
                tf.append(tf[i-1])
            else:
                tf.append(not tf[i-1])
        else:
            if tf[i]:
                tf.append(not tf[i-1])
            else:
                tf.append(tf[i-1])

    if tf[0] == tf[-1]:
        tf.pop(-1)
        flag = False
        if s[0] == 'o':
            if tf[0]:
                if tf[-1] == tf[1]:
                    flag = True
            else:
                if tf[-1] != tf[1]:
                    flag = True
        else:
            if tf[0]:
                if tf[-1] != tf[1]:
                    flag = True
            else:
                if tf[-1] == tf[1]:
                    flag = True

        if flag:
            for i in range(n):
                if tf[i]:
                    tf[i] = 'S'
                else:
                    tf[i] = 'W'
            print(''.join(tf))
            exit()

print(-1)