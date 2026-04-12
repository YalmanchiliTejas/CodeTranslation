def elimrow(lst):
    lst_after = []
    gset = []
    H1 = len(lst)
    for i in range(H1):
        gset = list(set(lst[i]))
        gset.sort()
        #print(gset)
        if gset[0] != '.':
            lst_after.append(lst[i])
    return lst_after

def trans(lst):
    return list(zip(*lst))

def main():
    H,W = map(int,input().split())

    grid = [list(str(input())) for _ in range(H)]
    grid_after = []
    grid_after = elimrow(grid)
    gridT = trans(grid_after)
    grid_after2 = elimrow(gridT)
    gridT2 = trans(grid_after2)
    #print(gridT2)
    for i in gridT2:
        print(*i,sep='')

if __name__ == "__main__":
    main()