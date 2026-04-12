h,w=map(int,input().split());A=[list(input())for _ in "_"*h]
def f(x,y):
  A[x][y]="."
  if x<h-1 and A[x+1][y]<".":return f(x+1,y)
  if y<w-1 and A[x][y+1]<".":return f(x,y+1)
f(0,0);print(['P','Imp']['#' in [x for a in A for x in a]]+'ossible')