N = input()
K = int(input())
n0 = int(N[0])

# 数値Nから,1の位の位置をp1とする[keta]桁の部分数値が全て0であるか
def if_part_zero (N, p1, keta):
  partnum = 0
  beki = keta - 1
  for i in range(p1 - keta + 1, p1 + 1):
    if int(N[i]) > 0:
      return False
  return True


t = 0
if (K == 1):
  t = n0 + (len(N) - 1) * 9

if (K == 2):
  enough = 0
  for i in range(0, len(N) - 1):
    if i > 0:
      pattern1 = 9
      enough = 1
    else:
      pattern1 = n0
    for j in range(i + 1, len(N)):
      if enough == 1 or if_part_zero(N, j - 1, j - i - 1) == False:
        pattern2 = 9
      else:
        pattern2 = int(N[j])
      # print ("i=" + str(i) + " j=" + str(j) + " p=" + str((pattern1 - 1) * 9 + pattern2))
      t += (pattern1 - 1) * 9 + pattern2
    
if (K == 3):
  enough1 = 0
  enough2 = 0
  for i in range(0, len(N) - 2):
    if i > 0:
      pattern1 = 9
      enough1 = 1
    else:
      pattern1 = n0
    for j in range(i + 1, len(N) - 1):
      if enough1 == 1 or if_part_zero(N, j - 1, j - i - 1) == False:
        pattern2 = 9
        enough2 = 1
      else:
        pattern2 = int(N[j])
      if pattern1 == 1 and pattern2 == 0:
        continue
      for k in range(j + 1, len(N)):
        if enough1 == 1 or enough2 == 1 or if_part_zero(N, k - 1, k - j - 1) == False:
          pattern3 = 9
        else:
          pattern3 = int(N[k])
        
        # print ("1=" + str(pattern1) + " 2=" + str(pattern2) + " 3=" + str(pattern3) + " p=" + str(((pattern1 - 1) * 9 + pattern2 - 1) * 9 + pattern3))
        t += ((pattern1 - 1) * 9 + pattern2 - 1) * 9 + pattern3

print (t)
