#include <stdio.h>

int main() {
    // For loop to run 1 million times
    for (long long int  i = 0; i <= 1000000; i++) {
        // Pointer for target and source
        FILE *source, *target;
        int g;

        // Source File from main drive
        source = fopen("C:\\Users\\hp\\Documents\\Code Files\\Visual Studio Code\\C\\Crash Computer\\amongus.png", "rb"); 
        if( source == NULL ) { printf("Press any key to exit...\n");} //exit(EXIT_FAILURE); 

        fseek(source, 0, SEEK_END);
        int length = ftell(source);
        fseek(source, 0, SEEK_SET);

        // counter to change the file name after every iteration of i
        char original[] = "Destination";
        char final[] = "";
        sprintf(final,"%s%d.png",original,i);

        // Openn file
        target = fopen(final, "wb"); 
        if( target == NULL ) { fclose(source); } //exit(EXIT_FAILURE);

        // Copy img code, and past into the target image
        for(g = 0; g < length; g++){
            fputc(fgetc(source), target);
        }

        // Close both target, and source
        fclose(source); 
        fclose(target);
    }
    return 0;
}