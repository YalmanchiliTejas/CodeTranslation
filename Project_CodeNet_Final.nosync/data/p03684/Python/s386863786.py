n = int(input())
a = [list(map(int, input().split())) for _ in range(n)]
a = sorted(a)
gra = []
for i in range(n):
  a[i].append(i)
for i in range(n-1):
  gra.append([a[i][2],a[i+1][2],a[i+1][0]-a[i][0]])
a = sorted(a,key= lambda x:x[1])
for i in range(n-1):
  gra.append([a[i][2],a[i+1][2],a[i+1][1]-a[i][1]])
union = [0] *  n
uc = 0
ans = 0
gra = sorted(gra, key = lambda x: x[2])
class UnionFind():
    #負の値はルートで集合の個数
    #正の値は次の要素を返す
    def __init__(self,size):
        self.table = [-1 for _  in range(size)]

    #集合の代表を求める
    def find(self,x):
        while self.table[x] >= 0:
            #根に来た時,self.table[根のindex]は負の値なのでx = 根のindexで値が返される。
            x = self.table[x]
        return x

    #併合
    def union(self,x,y):
        s1 = self.find(x)#根のindex,table[s1]がグラフの高さ
        s2 = self.find(y)
        if s1 != s2:#根が異なる場合
            if self.table[s1] != self.table[s2]:#グラフの高さが異なる場合
                if self.table[s1] < self.table[s2]:
                    self.table[s2] = s1
                else:
                    self.table[s1] = s2
            else:
                #グラフの長さが同じ場合,どちらを根にしても変わらない
                #その際,グラフが1長くなることを考慮する
                self.table[s1] += -1
                self.table[s2] = s1
        return
uni = UnionFind(n)
for i in range(len(gra)):
  hen = gra[i]
  if (uni.find(hen[0]) != uni.find(hen[1])):
    ans += hen[2]
    uni.union(hen[0],hen[1])
    uc += 1
  if uc == n-1:
    break
print(ans)