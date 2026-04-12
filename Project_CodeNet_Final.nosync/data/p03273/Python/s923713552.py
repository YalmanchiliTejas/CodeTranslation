def main():
    h, w = map(int, input().split())
    l = [input() for i in range(h)]
    
    row = [False]*h
    col = [False]*w

    for i in range(h):
        for j in range(w):
            if l[i][j] == '#':
                row[i] = True;
                col[j] = True;

    for i in range(h):
        if row[i]:
            for j in range(w):
                if col[j]:
                    print(l[i][j], end='')
            print()
      
   

    

if __name__=='__main__':
    main()