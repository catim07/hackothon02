#include <stdio.h>

int main() {
    int chose,allow=1,num=0,sizeMax,deleIndex;
    int array[100];
    do{
        printf("\nMenu:\n");
        printf("1. Nhap so phan tu va gia tri cho mang\n");
        printf("2. In ra gia tri cac phan tu\n");
        printf("3. Dem so luong cac phan tu chan va le trong mang\n");
        printf("4. Tim gia tri lon thu hai trong mang\n");
        printf("5. Them mot phan tu vao dau mang\n");
        printf("6. Xoa phan tu tai mot vi tri cu the\n");
        printf("7. Sap xep mang theo thu tu giam dan (Insertion sort)\n");
        printf("8. Tim kiem phan tu trong mang (Binary search)\n");
        printf("9. Sap xep mang theo thu tu giam dan (Bubble sort)\n");
        printf("10. Thoat\n");
        printf("Lua chon cua ban: ");
        scanf("%d",&chose);

        switch (chose){
            case 1: {
                printf("Moi ban nhap so phan tu: ");
                scanf("%d", &num);
                for(int i=0;i<num;i++) {
                    printf("Nhap phan tu [%d]: ",i);
                    scanf("%d", &array[i]);
                }
                sizeMax=num;
                allow=0;
                break;
            }
            case 2: {
                if (allow){
                    printf("Moi ban nhap gia tri cho mang truoc!\n");
                } else {
                    printf("Cac phan tu trong mang: ");
                    for(int i=0;i<num;i++){
                        printf("array[%d], ", array[i]);
                    }
                    printf("\n");
                }
                break;
            }
            case 3: {
                if (allow){
                    printf("Moi ban nhap gia tri cho mang truoc!\n");
                } else {
                    int even=0,odd=0;
                    for (int i=0;i<num;i++) {
                        if (array[i]%2==0) {
                            even++;
                        } else {
                            odd++;
                        }
                    }
                    printf("Co %d so chan trong mang\n",even);
                    printf("Co %d so le trong mang\n",odd);
                }
                break;
            }
            case 4: {
                if (allow || num < 2) {
                    printf("Moi ban nhap gia tri cho mang co it nhat 2 phan tu\n");
                } else {
                    int first=array[0],second=-1;
                    for (int i = 1; i < num; i++) {
                        if (array[i] > first) {
                            second = first;
                            first = array[i];
                        } else if (array[i]>second && array[i] != first) {
                            second = array[i];
                        }
                    }
                    if (second == -1) {
                        printf("Khong co gia tri lon thu hai trong mang.\n");
                    } else {
                        printf("Gia tri lon thu hai trong mang la: %d\n", second);
                    }
                }
                break;
            }
            case 5: {
                if (allow) {
                    printf("Moi ban nhap gia tri cho mang truoc!\n");
                } else {
                    int addValue;
                    printf("Nhap gia tri muon them: ");
                    scanf("%d", &addValue);
                    for (int i = num; i > 0; i--) {
                        array[i] = array[i - 1];
                    }
                    array[0] = addValue;
                    num++;
                    printf("phan tu da them la: \n");
                    for(int j=0;j<num;j++){
                    	printf("%d ",array[j]);
					}
                }
                break;
            }
            case 6: {
                if (allow) {
                    printf("moi ban nhap gia tri cho mang truoc\n");
                } else {
                    printf("nhap vi tri can xoa: ");
                    scanf("%d", &deleIndex);
                    if (deleIndex<0||deleIndex>=num) {
                        printf("vi tri khong hop le\n");
                    } else {
                        for (int i=deleIndex;i<num-1;i++) {
                            array[i]=array[i+1];
                        }
                        num--;
                       for(int j=0;j<num;j++){
                       	printf("%d ",array[j]);
					   }
                    }
                }
                break;
            }
            case 7: {
                if (allow) {
                    printf("moi ban nhap gia tri\n");
                } else {
                    for (int i=1;i<num;i++) {
                        int key=array[i];
                        int j=i-1;
                        while (j>=0&&array[j]<key) {
                            array[j+1]=array[j];
                            j--;
                        }
                        array[j + 1] = key;
                    }
                    printf("mang sau khi sap xep giam dan: ");
                    for (int i=0;i<num;i++) {
                        printf("%d ",array[i]);
                    }
                }
                break;
            }
            case 8: {
                if (allow) {
                    printf("moi ban nhap gia tri\n");
                } else {
                    int search, found = 0;
                    printf("nhap gia tri can tim: ");
                    scanf("%d", &search);
                    int start = 0, end = num - 1, mid;
                    while (start <= end) {
                        mid = (start + end) / 2;
                        if (array[mid] == search){
                            found = 1;
                            break;
                        } else if (array[mid] < search){
                            start = mid + 1;
                        } else {
                            end = mid - 1;
                        }
                    }
                    if (found) {
                        printf("gia tri %d co trong mang tai vi tri %d\n",search,mid);
                    } else {
                        printf("gia tri %d khong co trong mang\n",search);
                    }
                }
                break;
            }
            case 9:
            	if(allow){
            		printf("moi ban nhap gia tri\n");
				}else{
					for(int i=0;i<num-1;i++){
						for(int j=1;j-i-1;j++){
							if(array[i]<array[j]){
								int temp=array[j];
								array[j]=array[i];
								array[i]=temp;
							}
						}
					}
					for(int k=0;k<num;k++){
						printf("%d ",array[k]);
					}
				}
				break;
            case 10: {
                printf("tam biet cac ban hihi <3\n");
            }
            default: {
                printf("khong hop le\n");
                break;
            }
        }
    }while(chose!=10);
    return 0;
}

