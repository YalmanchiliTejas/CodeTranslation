def main():
    x,y,z=map(int,input().split())
    x -= z
    print(x//(y+z))
        
if __name__ == "__main__":
    main()