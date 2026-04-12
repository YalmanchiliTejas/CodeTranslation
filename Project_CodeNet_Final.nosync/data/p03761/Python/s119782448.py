def solve():
  N = int(raw_input())
  hist = []
  for i in range(N):
    s = raw_input()
    tmphist = [0 for i1 in range(26)]
    for c in s:
      tmphist[ord(c) - ord('a')] = tmphist[ord(c) - ord('a')] + 1

    #print 'i=',i,'hist=',hist,'tmphist=',tmphist
    if(i == 0):
      hist = tmphist
    else:
      for i2 in range(26):
        hist[i2] = min(hist[i2], tmphist[i2])
  ret = ''
  for i3 in range(26):
    ret += chr(ord('a') + i3) * hist[i3]
  return ret

if __name__ == '__main__' :
  print solve()