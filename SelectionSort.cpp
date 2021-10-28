#include <stdio.h>

int main(void) {
    int i,j, max, count;
	int m,n,p;
	int data_length=0;
	int temp_id=0;
	int temp_score=0;
	
	
	scanf("%d", &data_length);
	int student[data_length][4];
	
	for(m=0; m<data_length; m++){
		for(n=0; n<2; n++){
			scanf("%d", &student[m][n]);
		}
	}
	
	
	for(i=0; i<data_length; i++){
		max = i;
		for(j=i; j<data_length; j++){
			if(student[j][1] > student[max][1]){
				max=j;
			}
		}
		if(i!=max){
			temp_id = student[max][0];
			temp_score= student[max][1];
			for(count=max; count>i; count--){
				student[count][0]=student[count-1][0];
				student[count][1]=student[count-1][1];
			}
			student[i][0]=temp_id;
			student[i][1]=temp_score;
		}
	}
	
	for(p=0; p<data_length; p++){
		for(n=0; n<2; n++){
			printf("%d\n", student[p][n]);
		}
			
	}

    return 0;
}
