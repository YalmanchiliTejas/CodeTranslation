def main():
    H,W = map(int, input().split())
    grid = []
    for i in range(H):
        input_line = str(input())
        if '#' in input_line:
            grid.append(input_line)
    

    for j in range(W):
        del_flg = True
        for line in grid:
            if(line[j] == '#'):
                del_flg = False
                break
        if(del_flg):
            for i,line in enumerate(grid):
                line = line[:j] + '0' + line[j+1:]
                grid[i] = line
    
    for line in grid:
            print(line.replace('0',''))
    


if __name__ == "__main__":
    main()