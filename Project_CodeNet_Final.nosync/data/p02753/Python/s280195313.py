class StationAndBus:
    def __init__(self):
        self.result = False
    
    def check_combination(self, str_list):
        if str_list.count(str_list[0]) == 0 or str_list.count(str_list[0])==3:
            self.result = False
        else:
            self.result = True
        return self.result

if __name__ == "__main__":
    S=list(input())
    sab = StationAndBus()
    result=sab.check_combination(S)
    if result:
        print("Yes")
    else:
        print("No")